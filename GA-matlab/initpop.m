function pop = initpop(popsize, chromlength)
% 初始化种群，二进制编码
% popsize       input  种群规模
% chromlength   input  染色体长度
% pop           output popsize x chromelength的二进制矩阵
pop = round(rand(popsize, chromlength));
end