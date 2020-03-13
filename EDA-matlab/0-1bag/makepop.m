function pop = makepop(popsize, stuffsize, p)
% 初始化种群，但没有限制重量
% popsize       input  种群规模
% stuffsize     input  物品数目
% p             input  概率向量
% pop           output 构造的种群
pop = zeros(popsize, stuffsize);
for i =1:popsize
    pop(i, :) = makepopv(stuffsize, p);
end
end