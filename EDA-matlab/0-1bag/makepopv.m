function pop = makepopv(stuffsize, p)
% 初始化个体，没有限制重量
% stuffsize     input  物品数目
% p             input  概率向量
% pop           output 构造的个体
tpop = rand(1, stuffsize);
pop = zeros(1, stuffsize);
for j = 1:stuffsize
    if tpop(1, j) <= p(1, j)
        pop(1, j) = 1;
    end
end
end