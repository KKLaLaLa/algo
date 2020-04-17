//
//  main.cpp
//  mat2c++
//
//  Created by 王昆 on 2020/4/10.
//  Copyright © 2020 昆. All rights reserved.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <ctime>
#include "Mat.hpp"



#define test_Matarr2vec 1
#define test_Matsum 0
#define test_Matcumsum 0
#define test_Matfind 0
#define test_Matmax 0
#define test_Matmin 0
#define test_Matsort 0
#define test_extr 0

MatFunction MF;

int arr[5] = {1,4,5,2,0};
double arr_d[5] = {34.7,3.4,21.23,7.8,1.0};
int arr2[3][4] = {{1,2,3,4},{2,3,4,5},{3,4,5,6}};


int main(int argc, const char * argv[]) {
    
    vector<int> test_vec (arr,arr+sizeof(arr)/sizeof(int));
    vector<double> test_vec_d (arr_d,arr_d+sizeof(arr_d)/sizeof(double));
#if test_Matarr2vec
    
    vector<vector<int>> vec2;
    int *a = &arr2[0][0];
    vec2 = MF.Matarr2vec2(a, 3, 4);
    //MF.Matarr2vec2(arr2, 3, 4);

#endif
#if test_Matsum
    auto sum = MF.Matsum(test_vec);
    cout << "sum = " << sum << endl;
#endif
#if test_Matcumsum
    auto cumsum = MF.Matcumsum(test_vec);
    for (auto it = cumsum.begin(); it != cumsum.end(); it++) {
            cout << *it << " ";
        }
    cout << '\n';
#endif
#if test_Matfind
    auto vecget = MF.Matfind(test_vec, 3, ">");
    for (auto it = vecget.begin(); it != vecget.end(); it++) {
            cout << *it << " ";
        }
    cout << '\n';
#endif
#if test_Matmax
    auto vec_get = MF.Matmax(test_vec);
    cout << "maxvalue = " << vec_get.first << " maxvaluei = " << vec_get.second << endl;
#endif
#if test_Matmin
    auto vec_get_min = MF.Matmin(test_vec);
    cout << "maxvalue = " << vec_get_min.first << " maxvaluei = " << vec_get_min.second << endl;
#endif
#if test_Matsort
    auto vec_get_sort = MF.Matsort(test_vec, "max");
    for (auto it = vec_get_sort.first.begin(); it != vec_get_sort.first.end(); it++) {
        cout << *it << " ";
    }
    cout << '\n';
    for (auto it = vec_get_sort.second.begin(); it != vec_get_sort.second.end(); it++) {
        cout << *it << " ";
    }
    cout << '\n';
#endif
#if test_extr
    vector<vector<int>> array(5);
    
    for (int i = 0; i < array.size(); i++)
        array[i].resize(3);
     
    for(int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array[0].size();j++)
        {
            array[i][j] = (i+1)*(j+1);
            cout << " "<< array[i][j];
        }
    }
    
    vector<int> extcol_array(array[0].size());
    vector<int> extrow_array(array.size());
    extcol_array = MF.Matextract_col(array, 2);
    extrow_array = MF.Matextract_row(array, 1);
    
    cout << '\n';
    for (auto it = extcol_array.begin(); it != extcol_array.end(); it++) {
            cout << *it << " ";
        }
    cout << '\n';
    for (auto it = extrow_array.begin(); it != extrow_array.end(); it++) {
            cout << *it << " ";
        }
    cout << '\n';
#endif
    return 0;
}
