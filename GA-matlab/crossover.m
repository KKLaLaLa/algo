function [newpop] = crossover(pop, pc)
% 交叉
% pop       input  种群
% pc        input  变异概率
% newpop    output 新种群
[n, l] = size(pop);
newpop = zeros(n, l);
for i = 1:2:n-1   % 最少需剩余一行
    if rand < pc
        cpoint = round(rand * l);
        newpop(i, :) = [pop(i, 1:cpoint), pop(i+1, cpoint+1:l)];
        newpop(i+1, :) = [pop(i+1, 1:cpoint), pop(i, cpoint+1:l)];
    else
        newpop(i, :) = pop(i,:);
        newpop(i+1, :) = pop(i+1,:);
    end
end
end