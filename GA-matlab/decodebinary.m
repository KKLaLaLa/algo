function rpop = decodebinary(pop)
% 将二进制矩阵中的每一行转化为十进制数
% pop   input  二进制矩阵
% rpop  output 十进制列向量
[n, l] = size(pop);
temp = zeros(l, 1);
for i = 1:l
    temp(i,1) = 2^(l-i);
end
rpop = pop * temp;
end