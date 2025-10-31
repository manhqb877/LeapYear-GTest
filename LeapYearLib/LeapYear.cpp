
//bool IsLeapYear(int n)
//{
//    return (n % 4 == 0 && n % 100 != 0) || (n % 400 == 0);
//}

bool IsLeapYear(int n)
{
    if (n % 4 == 0 || (n % 100 == 0 && n % 400 == 0))
    {
        return true;
    }
    return false;
}

