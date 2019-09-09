#!/usr/bin/env python

from time import sleep

def get_next_line(p):
	line = ""

	while line[0:5] != "CYCLE":
		line = p.readline()

		if (len(line) == 0):
			sleep(0.001)
		elif line[0:5] != "CYCLE":
			print line[:-1]

	return line

def read_loop(p1, p2):
	oldline = ""

	while True:
		line1 = get_next_line(p1)
		line2 = get_next_line(p2)

		if line1 != line2:
			# TODO: Proper matching
			# TODO: Have a way to print registers

			# Lightrec might be lagging behind
			if line1[0:16] != line2[0:16]:
				cycle1 = int(line1[6:16], 16)
				cycle2 = int(line2[6:16], 16)

				if cycle1 < cycle2:
					print line2[:-1] + " - Dynarec"

					while cycle1 < cycle2:
						print line1[:-1] + " - Interpreter lagging behind"
						line1 = get_next_line(p1)
						cycle1 = int(line1[6:16], 16)

					while cycle1 > cycle2:
						print line2[:-1] + " - Dynarec lagging behind"
						line2 = get_next_line(p2)
						cycle2 = int(line2[6:16], 16)

					if cycle1 != cycle2:
						print "Mismatch!"
						print line1[:-1] + " - Interpreter"
						print line2[:-1] + " - Dynarec"
						print "State before the mismatch:"
						print oldline
						break

				if cycle2 < cycle1:
					print line1[:-1] + " - Interpreter"

					while cycle1 > cycle2:
						print line2[:-1] + " - Dynarec lagging behind"
						line2 = get_next_line(p2)
						cycle2 = int(line2[6:16], 16)

					while cycle1 < cycle2:
						print line1[:-1] + " - Interpreter lagging behind"
						line1 = get_next_line(p1)
						cycle1 = int(line1[6:16], 16)

					if cycle1 != cycle2:
						print "Mismatch!"
						print "INT: " + line1[:-1]
						print "JIT: " + line2[:-1]
						print "State before the mismatch:"
						print oldline
						break

				oldline = line1[:-1]
				print oldline + " - Match"
				continue

			print "Mismatch!"
			print line1[:-1] + " - Interpreter"
			print line2[:-1] + " - Dynarec"
			print "State before the mismatch:"
			print oldline
			break
		else:
			oldline = line1[:-1]
#			print oldline + " - Match"

def main():
	with open("/tmp/pcsx_int", "r") as p1:
		with open("/tmp/pcsx_jit", "r") as p2:
			read_loop(p1, p2)

if __name__ == '__main__':
	main()
