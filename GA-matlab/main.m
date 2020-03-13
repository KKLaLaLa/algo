clear
clc

popsize         = 30;       % 种群规模
chromlength     = 10;       % 染色体长度
pc              = 0.5;      % 交叉概率
pm              = 0.05;     % 变异概率
maxgen          = 20;       % 最大迭代数

lx = 5; ux = 10;

bestfit = zeros(1, maxgen);
bestobjvalue = zeros(2, maxgen);

% 优化
pop = initpop(popsize, chromlength); 
objvalue = calobjvalue(pop, lx, ux);
fitvalue = calfitvalue(objvalue,'max');
for i = 1:maxgen
    pop = selection(pop, fitvalue);     % 选择
    pop = crossover(pop, pc);           % 交叉
    pop = mutation(pop, pm);            % 变异

    objvalue = calobjvalue(pop, lx, ux);
    fitvalue = calfitvalue(objvalue, 'max');

    bestindex = bestindividual(pop, fitvalue, 'max');
    x = calobjvalue(pop, lx, ux);
    bestfit(1, i) = fitvalue(bestindex);
    bestobjvalue(1, i) = x(bestindex);
    bestobjvalue(2, i) = objvalue(bestindex);
    % fprintf('bestX: %f, bestY: %f\n', bestobjvalue(1, i), bestobjvalue(2, i));
end

figure(1);
fplot(@(x) 9 .* sin(5 .* x) + 8 .* cos(4 .* x), [lx, ux]);
hold on;
plot(bestobjvalue(1,:), bestobjvalue(2,:),'bo');
xlabel('x');
ylabel('y=9sin(5x)+8cos(4x)');
title('函数图');
grid on;
hold off;

figure(2);
plot(1:maxgen, bestfit(1,:));
xlabel('进化代数');
ylabel('最优适应度值');
title('最优适应度值图');
grid on;

bestX = bestobjvalue(1, end);
bestY = bestobjvalue(2, end);
fprintf('bestX: %f, bestY: %f\n', bestX, bestY);

