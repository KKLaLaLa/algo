# mat2c++
我的习惯是首先将想法使用matlab实现，之后，采用c++运用在工程中，毕竟这代表两类操作，一种是上层设计，不需要考虑太多底层的细节；一种是底层操作，也就是相当于实际操作，在过程中需要的思路远比顶层设计要来的复杂，需要完整的逻辑，为了减少将matlab转换为c++遇到函数重复实现的问题，特此将一些常用的操作用c++实现，主要用到vector、pair、string。

## 操作方法
首先定义MatFunction类：MatFunction MF;<br>

在使用的时候采用MF.函数即可<br>
为了方便所有函数的输入为向量，为此，提供了将二维数组转换为二维向量的函数Matarr2vec2<br>

函数介绍<br>

```
    *求和*
    //template <typename T> T Matsum(vector<T> vec);
    int Matsum(vector<int> vec);
    double Matsum(vector<double> vec);
    *二维数组转换为二维向量*
    vector<vector<int>> Matarr2vec2(int *arr,int row, int col);
    vector<vector<double>> Matarr2vec2(double *arr,int row, int col);
    *累计和*
    vector<int> Matcumsum(vector<int> vec);
    vector<double> Matcumsum(vector<double> vec);
    *寻找最值返回索引,提供>,>=,<,<=*
    vector<int> Matfind(vector<int> vec,int compval,string input);
    vector<int> Matfind(vector<double> vec,double compval,string input);
    *寻找最大值返回元素和索引*
    pair<int, int> Matmax(vector<int> vec);
    pair<double, int> Matmax(vector<double> vec);
    *寻找最小值返回元素和索引*
    pair<int, int> Matmin(vector<int> vec);
    pair<double, int> Matmin(vector<double> vec);
    *排序，返回排序结果和索引*
    pair<vector<int>, vector<int>> Matsort(vector<int> vec,string input);
    pair<vector<double>, vector<int>> Matsort(vector<double> vec,string input);
    *提取矩阵的行*
    vector<int> Matextract_row(vector<vector<int>> vec2, int ext_row);
    vector<double> Matextract_row(vector<vector<double>> vec2, int ext_row);
    *提取矩阵的列*
    vector<int> Matextract_col(vector<vector<int>> vec2, int ext_row);
    vector<double> Matextract_col(vector<vector<double>> vec2, int ext_row);
    *数组随机连续位置赋值*
    vector<int> Matrowset(vector<int> vec,int start,int end,int set_value);
    vector<double> Matrowset(vector<double> vec,int start,int end,double set_value);
    *数据统一操作+-x/*
    vector<int> Matopera(vector<int> vec,int opevalue,string operate);
    vector<double> Matopera(vector<double> vec,double opevalue,string operate);
    *判空函数*
    bool Matisempty(vector<int> vec);
    bool Matisempty(vector<double> vec);
```
```
int MatFunction::Matsum(vector<int> vec)
 输入：需要操作的向量
 操作：将里面的值求和
 输出：整型的求和结果

double MatFunction::Matsum(vector<double> vec)
输入：需要操作的向量
操作：将里面的值求和
输出：浮点型的求和结果

vector<vector<int>> MatFunction::Matarr2vec2(int *arr,int row, int col)
 输入：二维数组及其行数和列数
 操作：转换为二维向量
 输出：转换后的二维向量

vector<int> MatFunction::Matcumsum(vector<int> vec)
输入：需要操作的向量
操作：进行累积和计算
输出：整型的结果，以向量形式返回

vector<double> MatFunction::Matcumsum(vector<double> vec)
输入：需要操作的向量
操作：进行累积和计算
输出：浮点型的结果，以向量形式返回

vector<int> MatFunction::Matfind(vector<int> vec,int compval,string input)
输入：需要操作的向量，比较的值，哪种操作
操作：提供>,>=,<,<=四种操作，将输入向量中>,>=,<,<=compval的值，存放到返回的向量中
输出：整型的结果，以向量形式返回

vector<int> MatFunction::Matfind(vector<double> vec,double compval,string input)
输入：需要操作的向量，比较的值，哪种操作
操作：提供>,>=,<,<=四种操作，将输入向量中>,>=,<,<=compval的值，存放到返回的向量中
输出：浮点型的结果，以向量形式返回

pair<int, int> MatFunction::Matmax(vector<int> vec)
输入：需要操作的向量
操作：找寻最大的元素和对应的下标
输出：最大整型元素和下标，以pair类型返回

pair<double, int> MatFunction::Matmax(vector<double> vec)
输入：需要操作的向量
操作：找寻最大的元素和对应的下标
输出：最大浮点型元素和下标，以pair类型返回

pair<int, int> MatFunction::Matmin(vector<int> vec)
输入：需要操作的向量
操作：找寻最小的元素和对应的下标
输出：最小整型元素和下标，以pair类型返回

pair<double, int> MatFunction::Matmin(vector<double> vec)
输入：需要操作的向量
操作：找寻最小的元素和对应的下标
输出：最小浮点型元素和下标，以pair类型返回

pair<vector<int>, vector<int>> MatFunction::Matsort(vector<int> vec,string input)
输入：需要操作的向量和需要操作的方式
操作：将输入的向量按照要求的方式进行排序，主要有max：从小到大，min：从大到小，两种方式
输出：返回排序结果和对应的原下标向量（操作整型向量）

pair<vector<double>, vector<int>> MatFunction::Matsort(vector<double> vec,string input)
输入：需要操作的向量和需要操作的方式
操作：将输入的向量按照要求的方式进行排序，主要有max：从小到大，min：从大到小，两种方式
输出：返回排序结果和对应的原下标向量（操作浮点型向量）

vector<int> MatFunction::Matextract_row(vector<vector<int>> vec2,int ext_row)
 输入：输入需要提取的二维向量
 操作：提取出指定的行
 输出：该行的数据
vector<int> MatFunction::Matextract_col(vector<vector<int>> vec2, int ext_col)
输入：输入需要提取的二维向量
操作：提取出指定的列
输出：该列的数据

vector<int> MatFunction::Matrowset(vector<int> vec,int start,int end,int set_value)
 输入：输入需要操作的向量，位置和数据
 操作：将指定连续位置设置set_value
 输出：操作后的向量

vector<int> MatFunction::Matopera(vector<int> vec,int opevalue,string operate)
输入：输入需要操作的向量，数据和操作
操作：将向量进行操作
输出：操作后的向量

bool MatFunction::Matisempty(vector<int> vec)
 输入：需要判断的向量
 操作：判断
 输出：true or false


```

