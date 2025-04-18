# Копилка
* Республиканская Олимпиада Молдовы по информатике
* Год: 2017
* Класс: 10-12
* День: 1
* Задача: 3


Копилка представляет собой контейнер или специальное устройство для хранения и накопления монет. 
Как правило, это полые керамические статуэтки в форме животных, фруктов, овощей и т.п. 
Наиболее популярными являются копилки в форме поросенка. Сверху у такой копилки есть щель, в которую
можно бросать монеты. В Республике Молдова находятся в обращении монеты достоинством 1, 5, 10, 25 и 50 баней. 
Вес монеты определяется ее достоинством. В дидактических целях считается, что монеты имеют следующие веса:
* 1 бан ─ 1 грамм;
* 5 баней ─ 2 грамма;
* 10 баней ─ 3 грамма;
* 25 баней ─ 4 грамма;
* 50 баней ─ 5 граммов.

Известно, что в копилке находятся `N` монет с общим весом `G` грамма.

Через `M` обозначим минимальную сумму денег, которая может быть в копилке, а через
`K` ─ число всевозможных сочетаний монет, при условии, что их суммарный вес равен `G`.  

Например, для `N = 2` и `G = 4`, в копилке могут быть:
* 2 монеты по 5 баней, в общей сумме 10 баней;
* одна монета в один бан и одна монета в 10 баней, в общей сумме 11 баней.  

Очевидно, в этом примере минимальная сумма денег M = 10, а число всевозможных
сочетаний монет K = 2.

# Задание 
Напишите программу, которая, зная число монет `N`, содержащихся в копилке,
и их общий вес `G`, вычисляет минимальную сумму денег `M` и число всевозможных сочетаний
монет `K`, что могут быть в ней.

# Входные данные
Стандартный ввод содержит в единственной строке два целых числа,
разделенных пробелом: число монет N и их общий вес G (в граммах).

# Выходные данные
Стандартный вывод должен содержать в единственной строке два
целых числа, разделенных пробелом: минимальная сумма денег M (в банах) и число
всевозможных сочетаний монет K.

# Ограничения
* `1 ≤ N ≤ 100`; 
* `3 ≤ G ≤ 500`. 
* Время выполнения программы не должно превышать 0,1 секунды. 
Объем используемой оперативной памяти не должен превышать 1 Мегабайт. 
Исходный файл должен иметь имя `pusculita.pas`, `pusculita.c` или `pusculita.cpp`.

# Пример
Ввод
```
2 4
```

Вывод
```
10 2
```

# Похожие задачи
1. [518. Coin Change 2](https://leetcode.com/problems/coin-change-2/description/)