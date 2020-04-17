
popsize = 50;       % ��Ⱥ��ģ
birdsize = 30;      % ��������
w = 0.5;            % ����Ȩ��
c1 = 1.0;           % ��֪����
c2 = 2.0;           % �������
maxgen = 100;       % ����������

% ��ʼ��
x = randn(popsize, birdsize);
v = randn(popsize, birdsize);

% ��ʼ��pid��pgd
fitness = calfitness(x);
pid = x;
pidfit = fitness;
[bfit, bfiti] = min(fitness);
pgd = x(bfiti, :);
pgdfit = bfit;

% ��¼ÿ������ֵ
bestpidfit = zeros(popsize, 1);

for gen = 1:maxgen
    % �����ٶȺ�λ��
    v = w .* v + c1 .* rand .* (pid - x) + ... 
        c2 .* rand .* (repmat(pgd, popsize, 1) - x);
    x = x + v;

    % ����pid��pgd
    fitness = calfitness(x);
    index = find(fitness < pidfit);
    pid(index, :) = x(index, :);
    pidfit(index, 1) = fitness(index, 1);
    [bfit, bfiti] = min(fitness);
    bestpidfit(gen, 1) = bfit;
    if bfit < pgdfit
        pgd = x(bfiti, :);
        pgdfit = bfit;
    end
end
fprintf("������Сֵ�� %f\n", pgdfit);
figure(1);
plot(1:maxgen, bestpidfit);
title("ÿ��������Ӧ��ֵ�仯����");




