function npop = capacitylimit(pop, capacity, weights, p)
% 限制重量
% pop           input  种群
% capacity      input  背包容量
% weights       input  重量
% p             input  概率向量
% npop          output 新种群
npop = pop;
[popsize, stuffsize] = size(pop);
for i = 1:popsize
    wgtsum = weightsumv(npop(i, :), weights);
    while wgtsum > capacity
        npop(i, :) = makepopv(stuffsize, p);
        wgtsum = weightsumv(npop(i, :), weights);
    end
end
end