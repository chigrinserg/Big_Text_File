# Big_Text_File
Большой текстовый файл из элементов отсортированных массивов создан путем последовательной записи в текстовый файл данных из 10 динамических массивов размером по 50 млн. элементов каждый. Данные каждого следующего массива записывались в конец текстового файла установленным флагом std::fstream::app, последовательно увеличивая его размер. Использовался алгоритм сортировки подсчетом. Размер полученного файла - 2,27 Гб, время создания файла - 1 ч. 29 мин. 13 сек.
