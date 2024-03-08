#!/bin/bash
USAGE="Usage: $(basename "$0") filename [copy_count] [options]
    options:
        -s, --start_letter    Set first iterable letter for filename, ASCII only [default: 0]
"
INT_REGEX='^[0-9]+$'
FILEPATH_REGEX='^(..\/?)([a-zA-Z0-9\-\_\.\+]+\/)*[a-zA-Z0-9\-\_\.\+]+(\.[a-zA-Z0-9]{1,5})?$'
START_LETTER_REGEX='^[0-9a-z]?'
SPLIT_DOT_REGEX='^([^\.]+)\.(.+)$'
ENGLISH_ALPHABET_LENGHT=26

copy_count=5
filename="test.txt"
start_letter="0"

while [ -n "$1" ]; do
    case "$1" in
    -s | --start_letter)
        if [[ $1 =~ $START_LETTER_REGEX ]]; then
            start_letter="$2"
            shift
        else
            echo "Error: start_letter must be an integer or a english char in lower case"
            exit 1
        fi
        ;;
    *)
        if [[ $1 =~ $FILEPATH_REGEX ]]; then
            if [[ ! -f $1 ]]; then
                echo "Error: File \"$1\" doesn\`t exist"
                exit 1
            fi
            filename="$1"
        elif [[ $1 =~ $INT_REGEX ]]; then
            copy_count="$1"
        fi
        ;;
    esac
    shift
done

[[ $filename =~ $SPLIT_DOT_REGEX ]]
path="${BASH_REMATCH[1]}"
extension="${BASH_REMATCH[2]}"
for ((i = 0; i < $copy_count; i++)); do
    if [[ "$start_letter" =~ ^[0-9]+$ ]]; then
        new_file="${path}_${start_letter}.${extension}"
        cp "$filename" "$new_file"
        ((start_letter++))
    else
        new_file="${path}_${start_letter}.${extension}"
        while [ -e "$new_file" ]; do
            start_letter=$(echo "$start_letter" | sed 's/\(.\)/\1\1/')
            new_file="${path}_${start_letter}.${extension}"
        done
        cp "$filename" "$new_file"
        start_letter=$(echo "$start_letter" | tr "a-z" "b-za")
    fi
done

echo "Done!"
