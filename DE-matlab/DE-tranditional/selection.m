function newpop = selection(pop, npop)
% 选择（小值优化）
% pop           input  种群1（原始种群）
% pop           input  种群2（变异-交叉种群）
% newpop        output 选择后的种群
newpop = pop;
index = find(calobj(npop) <= calobj(pop));
newpop(index, :) = npop(index, :);
end