function crossoverpop = crossover(pop, mpop, cr)
% 交叉
% pop           input  种群
% mpop          input  变异后的种群
% cr            input  交叉概率
% crossoverpop  output 交叉后的种群
[popsize, chromlength] = size(pop);
crossoverpop = mpop;
r = rand(popsize, chromlength);
index = find (r > cr);
crossoverpop(index) = pop(index);
jrand = randi(chromlength, 1, popsize);
crossoverpop(sub2ind(size(crossoverpop), [1:popsize], jrand)) ...
    = mpop(sub2ind(size(mpop), [1:popsize], jrand));
end