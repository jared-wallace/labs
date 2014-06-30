all:
	uisp -dserial=$(PORT) -dpart=ATmega128 -dprog=mib510 --wr_fuse_h=0xd9 --wr_fuse_e=0xff --erase --upload if=$(HEX)

clean:
	uisp -dserial=$(PORT) -dpart=ATmega128 -dprog=mib510 --wr_fuse_h=0xd9 --wr_fuse_e=0xff --erase
	
