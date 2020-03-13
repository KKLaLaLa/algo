function childpop = selection(pop,fitvalue,leaving)




totalfit = sum(fitvalue);
fitvalue = fitvalue ./totalfit;
fitvalue = cumsum(fitvalue);  %计算概率分布
n = size(pop,1) - leaving;
rnum = sort(rand(n,1));
childpop = zeros(n,size(pop,2));

fitin = 1;
newin = 1;

while newin <=n
    if rnum(newin) < fitvalue(fitin)
        childpop(newin,:) = pop(fitin,:);
        newin = newin + 1;
    else
        fitin = fitin + 1;
    end
end
end

