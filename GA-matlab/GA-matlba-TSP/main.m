

citynum = 10; %城市规模
popsize = 50; %种群个数
chromlength = 10; %染色体长度
pc = 0.4; %交叉概率
pm = 0.05; %变异概率
maxgen = 150; %最大迭代次数

leavingfa = 5; %父代保留数量

pos = [1 2 2 3 1 4 5 5 6 4; 1 1 2 2 3 4 4 5 5 6];
D = distancematrix(pos);

gen = 0;
bestfit = zeros(1,maxgen);
bestlength = zeros(1,maxgen);

pop = initpop(popsize,citynum);
len = callength(D,pop);
fit = calfitness(len);

while gen<maxgen
    childpop = selection(pop,fit,leavingfa);
    leavingpop = selection(pop,fit,popsize - leavingfa);
    pop = [leavingpop;childpop];
    pop = crossover(pop,pc);
    pop = mutation(pop,pm);
    gen = gen+1;
    
    len = callength(D,pop);
    fit = calfitness(len);
    
    bestindex = bestindividual(fit);
    bestfit(1,gen) = fit(bestindex);
    bestlength(1,gen) = len(bestindex);
end
figure(1);
plot(1:maxgen, bestfit(1,:));
xlabel('进化代数');
ylabel('最优适应度值');
title('最优适应度值图');
grid on;

figure(2);
plot(1:maxgen, bestlength(1,:));
xlabel('进化代数');
ylabel('最优距离');
title('最优距离图');
grid on;

figure(3);
plot_route(pos, pop(bestindex,:));
grid on;
    



function bestindex = bestindividual(fitvalue)

[~,bestindex] = max(fitvalue);
end

function plot_pos(pos)

plot(pos(1,:),pos(2,:),'bo');
title('种群图（城市坐标图）');
end

function plot_route(pos, v)


plot_pos(pos);
hold on;
for i = 1:(size(v,2)-1)
    x1 = pos(1,v(i)); y1 = pos(2,v(i));
    x2 = pos(1,v(i+1)); y2 = pos(2,v(i+1));
    plot([x1, x2], [y1, y2], 'b');
    hold on;
end
plot([pos(1,v(end)), pos(1,v(1))], [pos(2,v(end)), pos(2,v(1))], 'b');
end