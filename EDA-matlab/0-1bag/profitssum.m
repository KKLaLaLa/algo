function pftsum = profitssum(pop, profits)
% 计算种群收益
% pop       input  种群
% profits   input  收益向量
% pftsum    output 种群收益
popsize = size(pop, 1);
pftsum = zeros(popsize, 1);
for i = 1:popsize
    pftsum(i, 1) = sum(profits(pop(i, :) ~= 0));
end
end