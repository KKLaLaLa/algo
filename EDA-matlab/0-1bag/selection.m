function spop = selection(pop, sn, profits)
% 选择
% pop           input  种群
% sn            input  选择数量
% profits       input  收益向量
% spop          output 选择的种群
pftsum = profitssum(pop, profits);
pftsum = pftsum';
[~, index] = sort(pftsum, 'descend');
index = index(1: sn);
spop = pop(index, :);
end