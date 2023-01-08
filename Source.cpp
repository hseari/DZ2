#include <iostream>
#include "Header.h"

//task1 Напишите функцию swap, которая меняет значения переданных аргументов
//Например, после вызова swap(a, b) в переменной a должно оказаться значение b, а в переменной b значение a
void swap(int* a, int* b)
{
	int t;
	t = *a; *a = *b; *b = t;

}

//Дано число n. Требуется создать массив a из n целых чисел и указатели на первый pa и последний pla элементы этого массива. 
//Нужно поменять с их помощью первый и последний элементы массива местами и вывести получившийся массив.
int task2()
{
	int n = 0;
	std::cout << "Введите длину массива: " << std::endl;
	std::cin >> n;
	int* a = new int[n];   //создаем массив

	int* ptrpa = &a[0];      //создаем указатель на первый элемент
	int* ptrpla = &a[n - 1];          //создаем указатель на последний элемент

	std::cout << "Введите элементы: ";  //вводим элементы массива
	for (int i = 0; i < n; i++)
		std::cin >> a[i];

	int tmp = a[0];   //меняем местами первый и последний элементы
	a[0] = a[n - 1];
	a[n - 1] = tmp;

	std::cout << "Массив: ";
	for (int i = 0; i < n; i++)    //выводим массив
		std::cout << a[i] << " ";

	std::cout << std::endl;

	delete[] a;      //освобождаем память
	a = nullptr;
	system("pause");
	return 0;
}

int task3()
{
	double a = 2;

	double* b = &a;
	double** p = &b;    //указатель на указатель
	std::cout << **p;    //выводим 2 через указатель на указатель

	system("pause");
	return 0;
}

//Ввести массив, состоящий из 12 элементов действительного типа. Расположить элементы в порядке убывания.
//Определить количество происшедших при этом перестановок.
int task4()
{
	double temp;
	srand((unsigned)time(NULL));
	double mass[12];
	int count = 0;

	std::cout << "Первоначальный массив: ";
	//заполнение массива случайными числами:
	for (int i = 0; i < 12; i++)
	{
		mass[i] = rand() % 10;
		std::cout << mass[i] << " ";
	}

	//сортировка
	for (int i = 0; i < 12 - 1; i++)
	{
		for (int j = i + 1; j < 12; j++)
		{
			if (mass[i] < mass[j])
			{
				temp = mass[i];
				mass[i] = mass[j];
				mass[j] = temp;
				count++;
			}
		}
	}

	std::cout << std::endl << "Конечный массив:       ";
	for (int i = 0; i < 12; i++)
	{
		std::cout << mass[i] << " ";
	}
	std::cout << std::endl << "Количество перестановок: " << count << " ";

	system("pause");
	return 0;
}

//Переписать элементы одномерного массива в другой массив такого же размера следующим образом: сначала должны идти
// все отрицательные элементы исходного массива, а затем все остальные. Использовать только один проход по
// исходному массиву. Сохранить тот порядок среди положительных и среди отрицательных элементов в результирующем
// массиве, который был в исходном массиве.
int task5()
{
	int size;
	srand((unsigned)time(NULL));
	std::cout << "Задайте размер массива: ";
	std::cin >> size;
	int* mass = new int[size];
	//заполняем и выводим массив
	std::cout << "Mассив: ";
	for (int i = 0; i < size; i++) {
		mass[i] = rand() % 201 + (100);
		std::cout << mass[i] << " ";
	}
	std::cout << std::endl;
	int* mass2 = new int[size];
	//пример: [-1; 43; 2; -43; 213]
	int i, j, k = 0;
	for (i = 0, j = 0, k = size - 1; i < size; ++i) {
		if (mass[i] < 0) { //проверяем на знак
			mass2[j] = mass[i];
			j++;
		}
		else {
			mass2[k] = mass[i];
			k--; //в моем примере сохраняется k = 1
		}
	}
	//тут получаем [-1; -43; 213; 2; 43], получается, нужно поменять местами все положительные числа (со 2 элемента по 4)
	for (i = k + 1, j = size - 1; i < j; ++i, --j) { //в момем примере получается i = 2; j = 4.
		std::swap(mass2[i], mass2[j]);
	}
	std::cout << "Получившийся массив: ";
	for (i = 0; i < size; i++) {
		std::cout << mass2[i] << " ";
	}
	delete[]mass;
	delete[]mass2;

	system("pause");
	return 0;
}

//Ввести массив, состоящий из 14 элементов действительного типа.Поменять местами первую половину со второй.
//Определить количество произведенных при этом перестановок.
int task6()
{
	double temp;
	int k = 0;
	srand((unsigned)time(NULL));
	double mass[14];
	int count = 0;

	for (int i = 0; i < 14; i++) {//вводим элементы массива
		std::cout << "Введите [" << i << "] элемент массива: ";
		std::cin >> mass[i];

	}
	std::cout << "Первоначальный массив: ";
	for (int i = 0; i < 14; i++) { //вывод введенного массива
		std::cout << mass[i] << " ";
	}
	std::cout << std::endl;


	//сортировка
	for (int i = 0; i < 7; i++)
	{
		int t = mass[7 + i];
		mass[7 + i] = mass[i];
		mass[i] = t;
		count++;
	}

	//выводим конечный
	std::cout << std::endl << "Конечный массив:       ";
	for (int i = 0; i < 14; i++)
	{
		std::cout << mass[i] << " ";
	}
	std::cout << std::endl << "Количество перестановок: " << count << std::endl;

	system("pause");
	return 0;
}

//Определить количество локальных минимумов в заданном числовом массиве.
//(Локальный минимум в числовом массиве – это последовательность трех рядом стоящих чисел,
// в которой среднее число меньше стоящих слева и справа от него).
int task7()
{
	srand((unsigned)time(NULL));
	int size; int count; // счетчик локальных минимумов
	std::cout << "Введите размер массива:  ";
	std::cin >> size;
	int* mass = new int[size];

	std::cout << "Первоначальный массив: ";
	//заполнение массива случайными числами и его вывод:
	for (int i = 0; i < size; i++)
	{
		mass[i] = rand() % 100;
		std::cout << mass[i] << " ";
	}
	//цикл для подсчета локального минимумуа
	for (int i = 0; i < size; i++)
	{
		if (i == 0 && mass[i] < mass[i + 1]) count++; // считаем первый элемент массива
		else if (i > 0 && i < size - 1 && mass[i] < mass[i - 1] && mass[i] < mass[i + 1]) count++; // все остальное
		else if (i == size - 1 && mass[i] < mass[i - 1]) count++; // считаем последний элемент массива
	}
	std::cout << "Количество локальных минимумов: " << count << std::endl;
	delete[]mass;

	system("pause");
	return 0;
}

int indmatr1(int* p, int n)     //нахождение индекса нуля в первой половине массива
{
	int j = 0;
	int b = 0;
	for (j = 0; j < n / 2; j++) {
		if (p[j] == 0) {
			b = j;
			return b;
		}
	}
}
int indmatr2(int* p, int n)    //нахождение индекса нуля во второй половине массива
{
	int j = 0;
	int a = 0;
	for (j = n; n / 2 <= j; j--) {
		if (p[j] == 0) {
			a = j;
			return a;
		}
	}
}

//Дана матрица. Известно, что в каждой строке этой матрицы присутствуют два и только два нулевых элемента. 
//Для каждой строки матрицы подсчитать сумму элементов, заключенных между этими двумя нулями. 
//Применить функцию, рассматривающую строки матрицы как одномерные массивы.
int task8()
{
	int n, i, j = 0;

	std::cout << "Укажите размерность матрицы: ";  //задаем размерность матрице
	std::cin >> n;

	srand((unsigned)time(NULL));
	int** p = NULL;
	p = (int**)malloc(n * sizeof(int*));

	//создаем матрицу
	for (i = 0; i < n; i++) {
		p[i] = (int*)malloc(n * sizeof(int));
	}

	//заполняем ее рандомными числами до 10
	for (i = 0; i < n; i++) {

		for (j = 0; j < n; j++)
		{
			p[i][j] = rand() % 10 + 1;

		}
		p[i][rand() % n / 2] = 0;     //ставим 0 на рандомное место в первой половине
		p[i][rand() % (n - n / 2) + n / 2] = 0;   //ставим 0 на рандомное место во второй половине
	}

	//вывод матрицы
	std::cout << "Полученная матрица: " << std::endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			std::cout << p[i][j] << " ";
		}
		std::cout << std::endl;
	}

	// код для нахождения суммы между нулями
	for (i = 0; i < n; i++) {
		int temp = 0;
		int indfirst0 = indmatr1(p[i], n);    //находим индекс первого нуля
		int indsecond0 = indmatr2(p[i], n);   //находим индекс второго нуля
		//std::cout << indfirst0 << " " << indsecond0 << std::endl;  
		if (indsecond0 - indfirst0 == 1) {     //если разница между индексами равно 1, то значит между ними нет элементов
			std::cout << "Между 0 нет элементов. ";
		}
		else {
			int j = indfirst0;
			while (j < indsecond0) {     //находим сумму между нулями
				temp += p[i][j];
				j++;
			}
		}
		std::cout << "Сумма между нулями: " << temp << std::endl;
	}

	for (i = 0; i < n; i++) {   //удаляем матрицу
		free(p[i]);
	}
	free(p);

	system("pause");
	return 0;
}

// Ввести массив, состоящий из 15 элементов целого типа. Упорядочить mассив так, чтобы все отрицательные
 // числа были расположены вначале по возрастанию, а все положительные – в конце по убыванию.
int task9()
{
	srand((unsigned)time(NULL));
	const int size = 15;
	int mass[size];
	for (int i = 0; i < size; i++) {//вводим элементы массива
		std::cout << "Введите [" << i << "] элемент массива: " << std::endl;
		std::cin >> mass[i];

	}
	std::cout << "Введенный массив: ";
	for (int i = 0; i < size; i++) { //вывод введенного массива
		std::cout << mass[i] << " ";
	}
	std::cout << std::endl;

	int count = 0;
	for (int i = 0; i < size; i++) { //подсчет количества отрицательных чисел
		if (mass[i] < 0) {
			count++;
		}
	}

	srand((unsigned)time(NULL));
	int* neg = new int[count]; //массив с отрицательными числами
	int cplu = (size - count); // количество положительных чисел в массиве
	srand((unsigned)time(NULL));
	int* plu = new int[cplu]; // массив с положительными
	int j = 0; // для отрицательного массива
	int l = 0; // для положительного

	for (int i = 0; i < size; i++) { //перебираем все числа по индексам
		if (mass[i] < 0) {
			neg[j] = mass[i]; //если отрицательное
			j++;
		}
		else {
			plu[l] = mass[i]; // если положительное
			l++;
		}
	}

	int temp;
	//сортировка
	//с отрицательными
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (neg[i] > neg[j])
			{
				temp = neg[i];
				neg[i] = neg[j];
				neg[j] = temp;
			}
		}
	}
	//с положительными
	for (int i = 0; i < cplu - 1; i++)
	{
		for (int j = i + 1; j < cplu; j++)
		{
			if (plu[i] < plu[j])
			{
				temp = plu[i];
				plu[i] = plu[j];
				plu[j] = temp;
			}
		}
	}
	srand((unsigned)time(NULL));
	int nmass[size];
	int j1 = 0;
	for (int i = 0; i < count; i++) { //записываем часть массива с отрицательными жлементами
		nmass[j1] = neg[i];
		j1++;
	}

	for (int i = 0; i < cplu; i++) { //записываем положительные элементы
		nmass[j1] = plu[i];
		j1++;
	}

	std::cout << "Полученный массив:  ";
	for (int i = 0; i < size; i++) { //вывод итогового массива
		std::cout << nmass[i] << " ";
	}
	delete[]neg;
	delete[]plu;

	return 0;
}

//Ввести два массива действительных чисел. Определить максимальные
//элементы в каждом массиве и поменять их местами.
int task10()
{
	srand((int)time(NULL));
	int n, m, i;

	std::cout << "Размер первого массива: "; std::cin >> n;
	std::cout << "Размер второго массива: "; std::cin >> m;

	double* a = new double[n], maxa = 0;    //создаем массивы
	double* b = new double[m], maxb = 0;

	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 10;         //заполняем первый
		std::cout << a[i] << " ";
		if (i == 0 || a[i] > maxa) maxa = a[i];  //находим в нем макс
	}
	std::cout << "  Макс элемент = " << maxa << std::endl;

	for (i = 0; i < m; i++)
	{
		b[i] = rand() % 10;         //заполняем второй
		std::cout << b[i] << " ";
		if (i == 0 || b[i] > maxb) maxb = b[i];   //находим в нем макс
	}
	std::cout << "  Макс элемент = " << maxb << std::endl;

	//меняем местами максимальные
	std::cout << "Новые массивы:" << std::endl;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i] == maxa) a[i] = maxb;
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;

	for (size_t i = 0; i < m; i++)
	{
		if (b[i] == maxb) b[i] = maxa;
		std::cout << b[i] << " ";
	}
	std::cout << std::endl;

	delete[]b;   //удаляем массивы
	delete[]a;
	system("pause");
	return 0;
}

//Сдвинуть циклически столбцы матрицы на один столбец вправо.
int task11()
{
	int n, i, j, temp = 0;

	std::cout << "Укажите размерность матрицы: ";  //задаем размерность матрице
	std::cin >> n;

	srand((unsigned)time(NULL));
	int** p = NULL;
	p = (int**)malloc(n * sizeof(int*));

	//создаем матрицу
	for (i = 0; i < n; i++) {
		p[i] = (int*)malloc(n * sizeof(int));
	}

	//заполняем ее рандомными числами
	for (i = 0; i < n; i++) {

		for (j = 0; j < n; j++)
		{
			p[i][j] = rand() % 10;

		}
	}

	//вывод матрицы
	std::cout << "Полученная матрица: " << std::endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			std::cout << p[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (i = n; i > 0; i--) {

		for (j = n - 1; j > 0; j--) {

			temp = p[i - 1][j - 1];
			p[i - 1][j - 1] = p[i - 1][j];
			p[i - 1][j] = temp;
		}
	}

	std::cout << std::endl << "В итоге..." << std::endl;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			std::cout << p[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (i = 0; i < n; i++) {   //удаляем матрицу
		free(p[i]);
	}
	free(p);

	system("pause");
	return 0;
}

int maximum(int* arr, int size)         //максимальный элемент в массиве
{
	int max;
	max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
int minimum(int* arr, int size)     //минимальный элемент в массиве
{
	int min;
	min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

//В матрице найти строки с максимальной и минимальной суммами элементов.
int task12()
{
	int n, i, j = 0;

	std::cout << "Укажите размерность матрицы: ";    //задаем размерность матрице
	std::cin >> n;

	srand((unsigned)time(NULL));
	int** p = NULL;
	p = (int**)malloc(n * sizeof(int*));

	//создаем динамический массив с массивами
	for (i = 0; i < n; i++) {
		p[i] = (int*)malloc(n * sizeof(int));
	}

	int* arr = new int[n];    //будущий массив с суммами
	//заполнение и вывод матрицы
	std::cout << "Полученная матрица: " << std::endl;
	for (i = 0; i < n; i++) {

		int sum = 0;
		for (j = 0; j < n; j++)
		{
			p[i][j] = rand() % 10 + 1;
			std::cout << p[i][j] << " ";
			sum += p[i][j];   //сумма строк
		}
		arr[i] = sum;        //загоняем все суммы в одномерный массив
		std::cout << std::endl;
	}

	std::cout << "Суммы строк: ";    //выводим массив с суммами
	for (i = 0; i < n; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	for (i = 0; i < n; i++) {    //ищем в нем макс. сумму
		int max = maximum(arr, n);
		if (max == arr[i])
			std::cout << "Строка с максимальной суммой: " << i + 1 << std::endl;
	}

	for (i = 0; i < n; i++) {   //ищем в нем мин. сумму
		int min = minimum(arr, n);
		if (min == arr[i])
			std::cout << "Строка с минимальной суммой: " << i + 1 << std::endl;
	}

	//удаляем все созданные массивы
	for (i = 0; i < n; i++) {
		free(p[i]);
	}
	free(p);
	delete[] arr;

	system("pause");
	return 0;
}

//Leetcode
int task13()
{
	const int n = 3;//размер первого массива (как количество цифр /= 0
	const int m = 3;//размер второго массива
	const int k = n + m;
	int nums1[k] = { 1, 2, 3, 0, 0, 0 };
	int nums2[m] = { 2, 5, 6 };
	int j = 0;
	for (int i = 0; i < k; i++) { //проверяем первый массив на наличие 0 (пустых мест) и если это условие верно,
		//записываем на это место число из второго
		if (nums1[i] == 0) {
			nums1[i] = nums2[j];
			j++;
		}
	}
	//сортировка пузырьком
	int temp = 0;
	for (int i = 0; i < k - 1; i++)
	{
		if (nums1[i] > nums1[i + 1]) {
			temp = nums1[i];
			nums1[i] = nums1[i + 1];
			nums1[i + 1] = temp;
		}
	}
	std::cout << "Полученный массив:  ";
	for (int i = 0; i < k; i++) { //вывод итогового массива
		std::cout << nums1[i] << " ";
	}
	
}

int indmin(int arr[], int size)
{
	for (int i = 0; i < size; i++) {
		int min = minimum(arr, size);  //находим в нем мин
		if (arr[i] == min) {
			int b = i + 1;
			return b;
		}
	}
}
int indmax(int arr[], int size)
{
	for (int i = 0; i < size; i++) {
		int max = maximum(arr, size);  //находим в нем макс
		if (arr[i] == max) {
			int a = i + 1;
			return a;
		}
	}
}

//Leetcode
int task14()
{
	int i, n, max, min;
	srand((unsigned)time(NULL));
	std::cout << "Размер массива: "; std::cin >> n;

	int* prices = new int[n];
	for (i = 0; i < n; i++)
	{
		prices[i] = rand() % 10;
		std::cout << prices[i] << " ";
	}
	std::cout << std::endl;
	int b = indmin(prices, n);
	std::cout << "Номер минимума: " << b << std::endl;
	int a = indmax(prices, n);
	std::cout << "Номер максимума: " << a << std::endl;
	if (a <= b)
		std::cout << "Выгода: " << 0 << std::endl;
	if (a > b)
		std::cout << "Выгода: " << maximum(prices, n) - minimum(prices, n) << std::endl;

	delete[] prices;
	system("pause");
	return 0;
}

int C(int n, int k) // функция выбора k элементов из  возможных: n! / (k!(n-k)!) (ну или сочетание без повторений)
{
	if (k == 0 || n == k)
		return 1;
	return C(n - 1, k - 1) + C(n - 1, k);
}

//Leetcode
int task15()
{
	int k, n;
	std::cout << "Введите количество строк: ";
	std::cin >> n;
	std::cout << "["; //открывем скобку для всего массива
	for (int l = 0; l < n; l++) { //цикл для как раз количества строк
		std::cout << "["; // открываем скобку для подмассивов, кроме последнего
		for (k = 0; k < l; k++) {//цикл для определения значения k-ого элемента в n-ой строке через сочетание без повторений
			C(l, k);
			std::cout << C(l, k) << ","; //запятые между элементами подмассивов
		}
		std::cout << "1], ";//закрывающая скобка для подмассивов, кроме последнего
	}
	std::cout << "["; // открывающая скобка последнего подмассива
	for (k = 0; k < n; k++) {//цикл для определения значения k-ого элемента в последней строке
		C(n, k);
		std::cout << C(n, k) << ",";
	}
	std::cout << "1]";//закрывающая скобка послднего подмассива
	std::cout << "]";//закрывающая скобка для всего массива
	return 0;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	/*int a = 5;
	int b = 0;
	swap(&a, &b);
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;*/

	//task2();
	//task3();
	//task4();
	//task5(); 
	//task6();
	//task7();
	//task8();
	//task9();
	//task10();
	//task11();
	//task12();
	//task13();
	//task14();
	//task15();

	return 0;
}