# Змея
* Республиканская Олимпиада Молдовы по информатике
* Год: 2018
* Класс: 10-12
* День: 2
* Задача: 3

В упрощенной версии известной, ставшей классикой жанра игре Snake, змея должна
съесть все яблоки из сада. Игра имеет очень простые правила:

1. В саду, на земле, разбросано n яблок. Положение каждого яблока i задается
декартовыми целыми координатами (xi, yi).

2. Начало системы координат находится в левом нижнем углу сада. Ось 0X
ориентирована слево направо, а ось 0Y – снизу вверх.

3. В начале игры, в сад заходит змея, цель которой − съесть все яблоки.

4. Текущее положение змеи задается декартовыми целыми координатами (xs, ys).

5. В исходном состоянии змея находится в точке с координатами (1, 1).

6. Система команд змеи включает команды ВВЕРХ, ВНИЗ, ВЛЕВО, ВПРАВО.
Выполнение каждой из этих команд состоит в перемещении змеи в указанном
направлении ровно на одну единицу длины.

7. Если текущие координаты змеи совпадают с координатами некоторого из яблок,
змея съедает его.

Цель игры состоит в передвижении змеи таким образом, чтобы все яблоки были
съедены, а длина пройденного пути было как можно короче.

Дорин явяется фанатом игры Snake. Он играет в эту игру давно и установил множество
рекордов. Но, к сожалению, кнопка ВНИЗ на его игровой консоли вышла из строя.

Вследствии этой неисправности, змея, независимо от ее текущего положения, может
выполнять только команды ВВЕРХ, ВЛЕВО, ВПРАВО.

Но Дорин не падает духом и расматривает эту неисправность как новый вызов. Даже
при неисправной кнопки, он намеревается установить новый рекод. Он не сомневается в
своей способности управлять змеей, однако прежде чем начать очередную игру, он хотел бы
знать длину наикратчайшего пути, при прохождении которого змея съедает все яблоки.

# Задание 
Напишите программу которая зная координаты каждого из n яблок, вычисляет длину `L` найкратчайшего пути,
при прохождении которого змея съедает все яблоки.

# Входные данные 
Стандартный вход содержит в первой строке целое число `n`. Каждая из следующих `n` строк входного файла содержит 
целые числа `xi, yi`, разделенные пробелами.
Строка `i + 1` входного файла содержит координаты яблока `i`.

# Выходные данные. 
Стандартный вывод должен содержать в единственной строке целое
число L.

# Ограничения. 
* `1 <= n <= 10000`;
* `1 <= xi, yi <= 10000`. 
* Время выполнения программы не должно превышать 0,05 секунд. 
Oбьем используемой оперативной памяти не должен превышать 1 Мегабайта. 
Исходный файл должен иметь имя sarpe.pas, sarpe.c или sarpe.cpp.

# Пример 1
Ввод 
```
5
2 2
5 3
7 3
8 4
4 6
```

Вывод
```
16
```