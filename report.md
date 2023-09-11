# Отчет по лабораторной работе № 1
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Никольский Константин Германович

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Git, Github, Gitlab etc
2. **Цель работы**: Ознакомиться с работой git
3. **Задание**:
- завести репозиторий (**общий под все лабораторные работы с отдельной папкой под каждую лр!**)
- отчет с листингом в Markdown (листинг - ctrl+c -> ctrl+v из терминала с форматированием в markdown)
- создать отдельную ветку в репозитории под задание
- создать коммит с листингом и отчетом
- смержить ветку в мейн
4. **Идея, метод, алгоритм решения задачи**: Опробовать работу с системой версий git, путём использования некоторых команд: git init
5. **Сценарий выполнения работы**: Создать репозиторий, создать ветку 1lab, создать файлы listing.md, report.md, создать коммит "first lab", смержить ветку в main
6. **Протокол**: 
```proksima@proksima-dude:~/labs_inf/labs_inf$ git init
Инициализирован пустой репозиторий Git в /home/proksima/labs_inf/labs_inf/.git/
proksima@proksima-dude:~/labs_inf/labs_inf$ git clone https://github.com/Proksima1/labs_inf.git
Клонирование в «labs_inf»...
remote: Enumerating objects: 3, done.
remote: Counting objects: 100% (3/3), done.
remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
Получение объектов: 100% (3/3), готово.
proksima@proksima-dude:~/labs_inf/labs_inf$ cd labs_inf
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf$ git checkout -b 1lab
Переключились на новую ветку «1lab»
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf$ touch listing.md
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf$ touch report.md
```
7. **Замечания автора** -
8. **Выводы**: Мне понравилась данная работа, потому что git очень важная часть в работе любого программиста и он всегда будет актуален. При работе 
