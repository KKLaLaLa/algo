function spop = selection(pop, sn, fitness)
% 选择
% pop       input  种群
% sn        input  优势群体规模
% fitness   input  种群适应度值
% spop      output 优势群体
[~, index] = sort(fitness);
index = index(1: sn);
spop = pop(index, :);
end