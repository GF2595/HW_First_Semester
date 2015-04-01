#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Reordering of elements in specified part of array
//Receives array pointer, pivot around which elements will be reordered, numbers of first and last element of array part
//Returns position of pivot in reordered array
int reordering(int *arr, int pivot, int firstElement, int lastElement)
{
	int firstPosition = firstElement;
	int i = firstElement + 1;

	swap(arr[pivot], arr[firstElement]);

	do
	{
		if (arr[firstPosition] >= arr[i])
		{
			swap(arr[firstPosition + 1], arr[i]);
			swap(arr[firstPosition], arr[firstPosition + 1]);
			firstPosition++;
		}
		i++;
	} while (i <= lastElement);

	return firstPosition;
}

//Sorts specified part of array using insertion method
//Receives array pointer, numbers of first and last element of array part
void insertionSort(int *arr, int firstElement, int lastElement)
{
	for (int i = 1; i <= lastElement; i++)
	{
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
		{
			swap(arr[j - 1], arr[j]);
		}
	}
}

//Sorts specified part of array using 'quick' method if length of part if more than 10 numbers, otherwise launches insertionSort
//Receives array pointer, numbers of first and last element of array part
void qsort(int *arr, int firstElement, int lastElement)
{
	if (lastElement - firstElement < 10)
	{
		insertionSort(arr, firstElement, lastElement);
	}
	else
	{
		int pivot = rand() % (lastElement - firstElement) + firstElement;
		int pivotPosition = reordering(arr, pivot, firstElement, lastElement);

		qsort(arr, firstElement, pivotPosition - 1);
		qsort(arr, pivotPosition + 1, lastElement);
	}
}

//Seeks out sought-for element using binary method
//Receives array, sought-out element, numbers of first and last elements of part of array for which search is used
//Returns true if element if found, false if element is not found
bool binarySearch(int *arr, int element, int firstElement, int lastElement)
{
	if (firstElement == lastElement)
	{
		return arr[firstElement] == element ? true : false;
	}
	else
	{
		if ((lastElement - firstElement) != 1)
		{
			int separator = (firstElement + lastElement) / 2;
			if (arr[separator] == element)
			{
				return true;
			}
			else
			{
				if (arr[separator] < element)
				{
					return binarySearch(arr, element, separator + 1, lastElement);
				}
				else
				{
					return binarySearch(arr, element, firstElement, separator - 1);
				}
			}
		}
		else
		{
			if (arr[firstElement] == element)
			{
				return true;
			}
			else
			{
				return arr[lastElement] == element ? true : false;
			}
		}
	}
}

void main()
{
	srand(time(nullptr));

	int n = 0;
	int k = 0;

	cout << "Insert n" << endl;
	cin >> n;
	cout << "Insert k" << endl;
	cin >> k;

	int const size = n;
	int *array = new(int[size]);

	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 1000000000;
	}

	qsort(array, 0, size - 1);

	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < k; i++)
	{
		int element = rand() % 1000000000;

		if (binarySearch(array, element, 0, size - 1))
		{
			cout << "Element " << element << " is found in array" << endl;
		}
		else
		{
			cout << "Element " << element << " is not found in array" << endl;
		}
	}

	delete[]array;
}



/*Общий случай:
Insert n
1000
Insert k
100
40 48 76 79 110 149 168 228 244 282 366 427 470 488 524 534 650 658 676 686 791
791 814 830 946 951 955 986 1024 1031 1035 1078 1083 1104 1134 1219 1228 1242 12
61 1269 1278 1310 1379 1380 1431 1449 1572 1607 1611 1616 1639 1640 1654 1706 17
46 1754 1758 1761 1768 1805 1808 1859 1894 1963 1984 2004 2067 2125 2142 2150 22
21 2342 2358 2368 2382 2426 2440 2526 2572 2584 2586 2604 2625 2643 2704 2752 27
70 2774 2815 2827 2827 2841 2885 2896 2910 2968 2973 2992 3031 3077 3086 3236 32
71 3284 3284 3363 3381 3395 3404 3408 3432 3445 3485 3587 3672 3681 3681 3686 37
20 3905 3990 3994 3995 4012 4017 4029 4121 4135 4171 4177 4198 4199 4217 4317 44
00 4470 4480 4546 4572 4641 4649 4663 4665 4685 4744 4777 4785 4792 4839 4878 48
78 4922 4992 5020 5061 5087 5178 5355 5382 5437 5521 5539 5586 5621 5660 5677 57
10 5731 5750 5795 5848 5852 5881 5917 5918 5927 5933 5950 6082 6082 6087 6123 61
76 6190 6209 6312 6346 6386 6387 6415 6453 6460 6498 6558 6566 6626 6633 6671 67
17 6842 6849 6910 6920 7008 7039 7041 7084 7140 7219 7223 7255 7358 7441 7493 75
63 7579 7580 7583 7604 7608 7639 7648 7672 7738 7787 7809 7863 7871 7907 7909 79
22 7949 7966 7970 7978 8005 8018 8041 8098 8159 8170 8190 8207 8256 8260 8286 82
90 8326 8341 8345 8349 8487 8536 8541 8566 8569 8576 8595 8611 8627 8656 8745 88
04 8870 8947 8947 8983 8993 9061 9076 9163 9245 9258 9275 9285 9286 9333 9347 93
54 9391 9395 9423 9448 9464 9475 9483 9490 9492 9544 9561 9562 9574 9611 9634 97
37 9815 9819 9821 9861 9897 9951 9982 9986 10043 10055 10090 10105 10114 10128 1
0151 10223 10237 10260 10280 10288 10291 10361 10397 10452 10546 10548 10562 106
03 10676 10759 10848 10854 10858 10869 10982 10983 11058 11075 11090 11095 11107
11168 11213 11259 11287 11342 11382 11401 11540 11555 11571 11573 11600 11605 1
1676 11682 11765 11785 11795 11802 11843 11848 11869 11886 11975 11992 12031 120
87 12138 12150 12274 12277 12316 12357 12384 12400 12403 12435 12464 12481 12568
12624 12644 12667 12690 12712 12745 12837 12840 12882 12911 12939 13065 13066 1
3114 13144 13145 13146 13154 13161 13163 13203 13259 13262 13288 13353 13391 134
22 13425 13434 13461 13469 13523 13595 13617 13699 13714 13779 13840 13925 13948
13978 14092 14121 14136 14176 14209 14231 14251 14279 14309 14334 14372 14384 1
4537 14572 14582 14619 14635 14691 14718 14740 14787 14791 14796 14970 14980 149
85 15056 15076 15086 15100 15147 15195 15226 15256 15283 15295 15304 15322 15326
15337 15339 15350 15390 15405 15420 15431 15455 15467 15480 15534 15534 15543 1
5558 15671 15675 15677 15679 15722 15757 15760 15778 15810 15849 15860 15920 159
49 15984 15989 16018 16091 16121 16180 16223 16255 16301 16348 16403 16485 16501
16564 16575 16600 16683 16696 16705 16791 16803 16812 16831 16833 16849 16883 1
6892 16950 16999 17013 17059 17117 17134 17213 17291 17354 17370 17392 17412 174
32 17500 17517 17527 17533 17548 17590 17591 17604 17642 17648 17655 17664 17673
17678 17702 17719 17732 17740 17768 17768 17778 17790 17805 17884 17963 17963 1
7996 18055 18101 18145 18208 18228 18382 18407 18454 18469 18489 18495 18522 185
45 18549 18598 18616 18645 18659 18700 18801 18823 18869 18873 18939 19028 19043
19103 19156 19175 19238 19251 19256 19339 19350 19352 19353 19369 19392 19401 1
9413 19415 19419 19459 19503 19570 19637 19653 19656 19770 19777 19856 19864 199
15 19958 19960 19979 19982 19983 20010 20080 20109 20110 20122 20153 20238 20261
20324 20325 20343 20348 20356 20394 20435 20460 20492 20498 20500 20549 20561 2
0596 20654 20700 20828 20859 20866 20884 20928 21003 21021 21070 21130 21154 212
25 21388 21404 21438 21601 21648 21658 21798 21811 21828 21834 21893 21945 21977
21991 21992 22062 22076 22092 22107 22114 22128 22232 22249 22277 22335 22347 2
2372 22384 22487 22496 22555 22585 22615 22617 22667 22669 22673 22682 22702 227
20 22740 22749 22786 22795 22844 22845 22849 22849 22909 22917 22932 22938 22946
22967 22970 22979 23019 23028 23076 23080 23084 23087 23091 23147 23180 23204 2
3217 23275 23371 23443 23499 23504 23516 23524 23580 23581 23653 23732 23764 237
74 23786 23792 23866 23891 23928 24034 24094 24106 24143 24149 24153 24201 24227
24239 24248 24306 24328 24328 24345 24361 24396 24446 24494 24505 24545 24547 2
4573 24596 24620 24622 24678 24689 24749 24777 24884 24923 25008 25045 25062 250
80 25147 25196 25264 25293 25342 25367 25377 25460 25493 25546 25608 25640 25660
25663 25665 25677 25680 25750 25755 25765 25777 25786 25791 25833 25852 25880 2
5896 25930 25947 26029 26090 26095 26131 26153 26269 26299 26300 26315 26322 263
36 26352 26388 26408 26412 26416 26464 26473 26507 26519 26521 26538 26596 26605
26708 26711 26733 26767 26850 26958 26974 26976 26996 27006 27103 27169 27180 2
7210 27211 27263 27273 27294 27366 27379 27382 27388 27435 27437 27465 27482 275
55 27585 27629 27653 27737 27751 27760 27800 27813 27870 27958 28053 28077 28107
28127 28159 28243 28308 28343 28363 28374 28381 28384 28401 28435 28471 28471 2
8510 28519 28532 28540 28574 28589 28605 28642 28711 28742 28752 28763 28812 288
23 28858 28859 28875 28900 28904 28923 29039 29057 29075 29088 29121 29125 29191
29196 29197 29206 29255 29287 29298 29342 29368 29375 29459 29487 29595 29717 2
9775 29809 29878 29930 29952 29996 30060 30068 30099 30100 30215 30232 30236 302
39 30305 30310 30396 30403 30442 30576 30580 30580 30593 30609 30629 30643 30662
30767 30784 30790 30802 30822 30830 30872 30930 30987 31000 31037 31088 31103 3
1128 31202 31221 31228 31241 31278 31364 31416 31504 31532 31542 31584 31618 316
32 31637 31684 31832 31865 31867 31890 31891 31893 32009 32058 32098 32126 32158
32175 32180 32205 32207 32238 32257 32258 32263 32281 32282 32376 32380 32401 3
2415 32484 32490 32505 32513 32515 32530 32589 32589 32608 32753
Element 32717 is not found in array
Element 8775 is not found in array
Element 13450 is not found in array
Element 30044 is not found in array
Element 24068 is not found in array
Element 11494 is not found in array
Element 18211 is not found in array
Element 16243 is not found in array
Element 11870 is not found in array
Element 4918 is not found in array
Element 25680 is found in array
Element 29904 is not found in array
Element 28632 is not found in array
Element 4439 is not found in array
Element 27781 is not found in array
Element 30122 is not found in array
Element 15645 is not found in array
Element 25939 is not found in array
Element 15217 is not found in array
Element 11653 is not found in array
Element 6126 is not found in array
Element 31990 is not found in array
Element 28290 is not found in array
Element 20392 is not found in array
Element 967 is not found in array
Element 13792 is not found in array
Element 29863 is not found in array
Element 14290 is not found in array
Element 13248 is not found in array
Element 25560 is not found in array
Element 19289 is not found in array
Element 17193 is not found in array
Element 20401 is not found in array
Element 4451 is not found in array
Element 3292 is not found in array
Element 13683 is not found in array
Element 5273 is not found in array
Element 11925 is not found in array
Element 13250 is not found in array
Element 32392 is not found in array
Element 21569 is not found in array
Element 8744 is not found in array
Element 14258 is not found in array
Element 29703 is not found in array
Element 6172 is not found in array
Element 28875 is found in array
Element 26471 is not found in array
Element 21321 is not found in array
Element 27506 is not found in array
Element 28348 is not found in array
Element 9211 is not found in array
Element 8083 is not found in array
Element 4285 is not found in array
Element 12185 is not found in array
Element 24934 is not found in array
Element 12432 is not found in array
Element 9812 is not found in array
Element 10356 is not found in array
Element 4162 is not found in array
Element 1278 is found in array
Element 32326 is not found in array
Element 14373 is not found in array
Element 21713 is not found in array
Element 11687 is not found in array
Element 11657 is not found in array
Element 2532 is not found in array
Element 12096 is not found in array
Element 25747 is not found in array
Element 5716 is not found in array
Element 1559 is not found in array
Element 31021 is not found in array
Element 9340 is not found in array
Element 29129 is not found in array
Element 17768 is found in array
Element 23656 is not found in array
Element 21634 is not found in array
Element 7383 is not found in array
Element 14875 is not found in array
Element 9974 is not found in array
Element 23584 is not found in array
Element 11359 is not found in array
Element 926 is not found in array
Element 8284 is not found in array
Element 13151 is not found in array
Element 3221 is not found in array
Element 8290 is found in array
Element 17434 is not found in array
Element 17225 is not found in array
Element 12202 is not found in array
Element 29162 is not found in array
Element 1397 is not found in array
Element 10913 is not found in array
Element 4008 is not found in array
Element 18210 is not found in array
Element 121 is not found in array
Element 15057 is not found in array
Element 1949 is not found in array
Element 24817 is not found in array
Element 15423 is not found in array
Element 16676 is not found in array
*/