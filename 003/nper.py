import sys

def main():
	try:
		sequence = list(str(sys.argv[1]))
		ldc = sequence[-1:]
		pivot = -1
		for num in reversed(xrange(len(sequence)-1)):
			if sequence[num] > ldc[0]:
				ldc.insert(0, sequence[num])
				pivot = sequence[num-1]
			else:
				pivot = sequence[num]
				break
		to_swap = min(x for x in sequence if x > pivot)
		i = sequence.index(pivot)
		j = sequence.index(to_swap)
		k = ldc.index(to_swap)
		ldc[k] = sequence[i]
		sequence[i], sequence[j] = sequence[j], sequence[i]
		ldc = list(reversed(ldc))
		if len(ldc) == 1:
			sequence[-1:] = ldc
		else:
			sequence[len(ldc)-1:] = ldc
		print("The next permutation in a totally ordered set would be: "+''.join(sequence))
	except Exception:
		print("Usage: python nper.py sequence")
		print(Exception)
	sys.exit(0)

if __name__ == "__main__":
	main()
