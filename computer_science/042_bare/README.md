# Бруски
* Республиканская Олимпиада Молдовы по информатике
* Год: 2019
* Класс: 11
* День: 1
* Задача: 2


Рассматривается заготовка в деревянного стержня длиной `L`. Из этой заготовки
необходимо вырезать бруски меньшей длины, размер каждого из которых выбирается из
множества `{D1, D2, …, Dk}`.

Очевидно, в общем случае, существует несколько возможных вариантов резки. Они
получаются путем выбора определенных размеров из множества `{D1, D2, …, Dk}` и
установлением чисел подлежащих разрезанию брусков `n1, n2, ..., nk`, в соответствии с
выбранными размерами.

Чтобы эффективно использовать сырье, а также не загрязнять окружающую среду,
технолог желает выбрать такие размеры и числа подлежащих резке брусков, при которых
длина `R` оставшейся после резки куска заготовки была минимальной.

Например, для `L=10, k = 2, D1 = 2, D2 = 4` минимальное значение `R = 0` будет получено
при использовании одного из следующих методов резки:
1) отрезается один брусок размера D1 = 2 и два бруска размера D2 = 4;
2) отрезаются пять брусков размера D1 = 2;
3) отрезаются три бруска размера D1 = 2 и одит брусок размера D2 = 4.


# Задание. 
Составьте программу, которая, зная длину заготовки `L` и размеры `{D1, D2, .., Dk }`, вычисляет минимально 
возможную длину `R` оставшейся части заготовки.

# Входные данные. 
Первая строка стандартного ввода содержит целые числа `L` и `k`, разделенные пробелом. 
Вторая строка стандартного ввода содержит целые числа `D1, D2, .., Dk`, разделенные пробелами.

# Выходные данные. 
* Стандартный вывод должен содержать в одной строке целое число `R`.
* Ограничения `0 < L ≤ 4000000`; `k ≤ 1000`; `0 < D[i] < L, i = 1, 2,... , k`. 
* Длина `L` и размеры `Di` являются целыми числами. 
* Исходный файл должен иметь имя bare.pas, bare.c или bare.cpp.

# Пример 1. 
 
Ввод
```
10 3
2 3 4
```

Вывод
```
0
```

# Пример 2. 
 
Ввод
```
10 2
6 7
```

Вывод
```
3
```

# Пример 3. 
 
Ввод
```
39999 7
30 40 50 60 70 80 90
```

Вывод
```
9
```