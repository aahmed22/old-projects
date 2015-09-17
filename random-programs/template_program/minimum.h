template <class T>
T minimum(T value1, T value2, T value3)
{
	T minimumValue = value1;
	if(value2 < minimumValue)
		minimumValue = value2;

	if(value3 < minimumValue)
		minimumValue = value3;

	return minimumValue;
}