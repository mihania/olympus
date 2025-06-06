# Регионы
* Республиканская Олимпиада Молдовы по информатике
* Год: 2017
* Класс: 7-9
* День: 2
* Задача: 2


Известно, что натуральные числа могут быть представлены в различных системах
нумерации. Например, в двоичной системе, десятичное число 37 представляется следующим
образом:
* `37(10) = 1 ∙ 2^5 + 0 ∙ 2^4 + 0 ∙ 2^3 + 1 ∙ 2^2 + 0 ∙ 2^1 + 1 ∙ 2^0 = 1001012(2)`  

Однако не все знают, что натуральные числа могут быть представлены и в
факториальной системе счисления, например:
37(10) = 1 ∙ 4! + 2 ∙ 3! + 0 ∙ 2! + 1 ∙ 1! = 1201!
;
463(10) = 3 ∙ 5! + 4 ∙ 4! + 1 ∙ 3! + 0 ∙ 2! + 1 ∙ 1! = 34101!
.
Общий вид этого представления:
* `a = dn ∙ n! + dn−1 ∙ (n − 1)! + ⋯ + di∙ i! + ⋯ + d2 ∙ 2! + d1 ∙ 1!`,  
где `dn, dn−1, … , di , … , d2, d1` натуральные числа, `dn > 0` и `di ≤ i`.

# Задание 
Напишите программу, которая, зная натуральное число `a`, вычисляет его представление в 
факториальной системе счисления.

# Входные данные
Стандартный ввод содержит в единственной строке целое число `a`.

# Выходные данные. 
Стандартный вывод должен содержать в единственной строке целые числа `dn, dn−1, … , di , … , d2, d1`, 
разделенные пробелом.

# Ограничения. 
* `1 ≤ a ≤ 1018` 
* Время выполнения программы не должно превышать 0,2 секунды. 
* Объем используемой оперативной памяти не должен превышать 1 Мегабайт.
* Исходный файл должен иметь имя `factor.pas`, `factor.c` или `factor.cpp`.

# Пример
Ввод
```
463
```

Вывод
```
3 4 1 0 1
```

# Похожие задачи
1. [338. Counting Bits](https://leetcode.com/problems/counting-bits/)
2. [405. Convert a Number to Hexadecimal](https://leetcode.com/problems/convert-a-number-to-hexadecimal/)
