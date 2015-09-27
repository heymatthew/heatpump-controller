push:
	rm *.bin
	particle compile photon
	particle flash bager_bager *bin

clean:
	rm *.bin
