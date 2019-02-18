
#include <algorithm>
#include <vector>
#include <iterator>


template<typename It, typename ItOut>
void MergeSort(It first1, It last1, It first2, It last2, ItOut out)
{
    auto it1 = first1;
    auto it2 = first2;
    while (it1 != last1 && it2 != last2)
    {
        if (*it1 < *it2)
        {
            out = *it1;
            *it1++;
        }
        else
        {
            out = *it2;
            it2++;
        }
    }

    if (it1 != last1 && it2 == last2)
    {
        std::for_each(it1, last1, [&out](auto v) { out = v; });
    }
    else if (it1 == last1 && it2 != last2)
    {
        std::for_each(it2, last2, [&out](auto v) { out = v; });
    }

}

#include <iostream>

int main()
{
    std::vector<int> v1 = { 1,2,4,6,8,10 };
    std::vector<int> v2 = { 3,4,5,7,11,12,13,14 };
    std::vector<int> result;

    MergeSort(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(result));

    for (auto res : result)
        std::cout << res << ",";

    std::cout << std::endl;
    system("pause");
    return 0;
}