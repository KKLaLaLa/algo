function np = makep(pop, p, alpha)
% 更新概率向量
% pop           input  种群
% p             input  概率向量
% alpha         input  学习速率
% np            output 更新后的概率向量
popsize = size(pop, 1);
np = (1 - alpha) .* p + alpha .* sum(pop) ./ popsize;
end