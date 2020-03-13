function pop = initpop(popsize,chromlength)


pop = zeros(popsize,chromlength);
for i = 1:popsize
    pop(i,:) = randperm(chromlength);
end
end