# **Задача 0.1. Порядок перемножения матриц**
*Имя входного файла: input.txt <br/>
Имя выходного файла: output.txt <br/>
Ограничение по времени: 1 с <br/>
Ограничение по памяти: 256 МБ*

Дана последовательность из s матриц A1, A2, …, As. Требуется определить, в каком порядке их следует перемножать, чтобы число атомарных операций умножения было минимальным. Матрицы предполагаются совместимыми по отношению к матричному умножению (т. е. число столбцов матрицы Ai − 1 совпадает с числом строк матрицы Ai).

Будем считать, что произведение матриц — операция, которая принимает на вход две матрицы размера k × m и m × n и возвращает матрицу размера k × n, затратив на это kmn атомарных операций умножения. (Базовый тип позволяет хранить любой элемент итоговой и любой возможной промежуточной матрицы, поэтому умножение двух элементов требует одной атомарной операции.)

Так как перемножение матриц ассоциативно, итоговая матрица не зависит от порядка выполнения операций умножения. Другими словами, нет разницы, в каком порядке расставляются скобки между множителями, результат будет один и тот же.

## **Формат входных данных**
В первой строке задано число s матриц (2 ≤ s ≤ 100). В последующих s строках заданы размеры матриц: строка i + 1 содержит через пробел число ni строк и число mi столбцов матрицы Ai (1 ≤ ni, mi ≤ 100). Гарантируется, что mi совпадает с ni + 1 для всех индексов i от 1 до s − 1.
## **Формат выходных данных**
Выведите минимальное число атомарных операций умножения, необходимое для перемножения s матриц.

# **Примеры**
> input.txt :<br/>
3<br/>
2 3<br/>
3 5<br/>
5 10<br/>
output.txt :<br/>
130

> input.txt :<br/>
4<br/>
20 5<br/>
5 35<br/>
35 4<br/>
4 25<br/>
output.txt :<br/>
3100