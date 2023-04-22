	cout << "Попытка открыть файл для чтения!" << endl;
	fin.open(path);
	cout << "Файл успешно открыт." << endl;
	while (!fin.eof())
	{
		str = "";
		getline(fin, str);
		
	}
	newstr = regex_replace(str, regex("0"), "ноль");
	newstr = regex_replace(newstr, regex("1"), " один ");
	newstr = regex_replace(newstr, regex("2"), " два ");
	newstr = regex_replace(newstr, regex("3"), " три ");
	newstr = regex_replace(newstr, regex("4"), " четыре ");
	newstr = regex_replace(newstr, regex("5"), " пять ");
	newstr = regex_replace(newstr, regex("6"), " шесть ");
	newstr = regex_replace(newstr, regex("7"), " семь ");
	newstr = regex_replace(newstr, regex("8"), " восемь ");
	newstr = regex_replace(newstr, regex("9"), " девять ");
	cout << newstr;
}
		
	

