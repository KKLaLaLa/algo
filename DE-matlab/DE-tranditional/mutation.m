function mutationpop = mutation (pop, F)
% 变异操作
% pop           input  种群
% F             input  缩放因子
% mutationpop   output 变异后种群
[popsize, chromlength] = size(pop);
mutationpop = zeros(popsize, chromlength);
for i = 1:popsize
    % 取3个互异的索引 r0 r1 r2
    r = randperm(popsize);
    index = find (r ~= i);
    rn = r(index(1:3));
    r0 = rn(1); r1 = rn(2); r2 = rn(3);
%     fprintf('i = %d, r0 = %d, r1 = %d, r2 = %d\n', i, r0, r1, r2);

    mutationpop(i,:) = pop(r0,:) + F .* (pop(r1,:) - pop(r2,:));
end
end