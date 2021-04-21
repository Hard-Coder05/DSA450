// METHOD 1 : when we have to edit the variable directly and no auxiliary space is available
string reverseWord(string str)
{
	int start = 0;
	int end = str.length() - 1;
	while (start < end)
	{
		char c = str[start];
		str[start] = str[end];
		str[end] = c;
		start++;
		end--;
	}
	return str;
}

//METHOD 2: When we use STL
string reverseWord(string str)
{

	reverse(str.begin(), str.end());
	return str;
}