" Found this on the reduce library docs, think it's super clever "
" if not an exact implementation of sieve "

(reduce
  (fn [primes number]
    (if (some zero? (map (partial mod number) primes))
      primes
      (conj primes number)))
  [2]
  (take 1000 (iterate inc 3)))
