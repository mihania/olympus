# Дерево 

Республиканская Олимпиада Молдовы по информатике
* Год: 2022
* Класс: 12
* День: 1
* Задача: 1

---
Отец Степана - местный архитектор. Он собирается спроектировать местность на берегу
Днестра. Предполагается, что в населенном пункте будут не менее `N` домов, расположенных
вдоль реки в виде двоичного дерева, где каждый дом будет представлять собой узел. Чтобы
оптимизировать расположение домов, отец предлагает Степану решить следующую задачу:
задав натуральные числа `N`, `A`, `B`, определить минимальную высоту двоичного дерева,
содержащего не менее `N` узлов, зная что ребра к дочерним узлам слева имеют длину `А`, а к
дочерним узлам справа - `В`.


# Задание 
Напишите программу, которая, имея `Т` значений `N`, `A`, `B` с указанным выше
значением определяет минимальную высоту каждого дереваю

# Входные данные
Линия входных данных содержит натуральное число `T`, обозначающее количество деревьев. 
В следующих `Т` строках 3 натуральных числа `N`, `A`, `B`,
разделенные пробелом с указанным выше значением.

# Выходные данные 
Вывести `Т` линий. Линия `і` представляет единственное натуральное
число, представляющее минимальную высоту дерева `і`.


# Ограничения 
* 1 < T < 5; 
* 1 < N, A, B < 10^9. 

Ограничения, связанные со временем
выполнения и используемой памятью даны в общем описании задач, предложенных для
решения. Файл с исходным кодом должен называться `arbore.pas`, `arbore.cpp`.

# Баллы 
Тесты разбиты на группы следующим образом:
* Для 10% тестов N, A, B < 100
* Для 10% тестов N < 10^5
* Для 10% тестов N < 10^6
* Для 15% тестов А, В < 10^4

# Пример 1
Входные данные
```
4
2 1 3
4 2 1
100 13 17
100000 127 81
```


Выходные данные
```
1
2
90
1642
```

# Пояснение 
В первом случае строится двоичное дерево, имеющее только корень с левым
дочерним узлом. Для второго случая строится двоичное дерево, имеющее корни с
обоими дочерними узлами, у правого дочернего узла тоже есть дочерний узел.