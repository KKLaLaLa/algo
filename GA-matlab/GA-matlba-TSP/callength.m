function len = callength(D, pop)
% 计算种群中每个个体所对应的路线距离
% D             input  距离矩阵
% pop           input  种群
% len           output 距离
n = size(pop,1);
len = zeros(n, 1);
for i = 1:n
    for j = 1:(size(pop,2)-1)
        len(i,1) = len(i,1) + D(pop(i, j), pop(i, j+1));
    end
    len(i,1) = len(i,1) + D(pop(i,1), pop(i,end));
end
end