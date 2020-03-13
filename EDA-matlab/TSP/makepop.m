function pop = makepop(popsize, citysize, p)
% 制作种群
% popsize       input  种群规模
% citysize      input  城市数量
% p             input  概率矩阵
% pop           output 种群
pop = zeros(popsize, citysize);

for i = 1:popsize
    for j = 1:citysize
        if j == 1   % 随机产生第一个城市
            pop(i, j) = randi(citysize);
        else        % 使用轮盘赌法选择下一个城市
            cityp = p(pop(i, j-1), :);      % 找出备选城市
            cityp(pop(i, 1:j-1)) = 0;       % 已经访问过的概率为0
            sumcityp = sum(cityp);          % 开始轮盘赌法
            cityp = cityp ./ sumcityp;
            cityp = cumsum(cityp);
            index = find(cityp >= rand);

            % 上一代优势群体中没有城市对记录，则找一个城市填充
            if isempty(index)
                tempcity = 1:1:citysize;
                tempcity(pop(i, 1:j-1)) = 0;
                tempindex = find(tempcity > 0);
                index = tempindex(1);
            end
            pop(i, j) = index(1);
        end
    end
end
end