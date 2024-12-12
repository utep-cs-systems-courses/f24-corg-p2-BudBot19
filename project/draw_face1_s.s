	.arch msp430g2553
	.p2align 1, 0
	.text


	.global draw_face1

draw_face1:
	call #lcd_init

	mov #0x053f, r12
	call #clearScreen

	sub #4, r1
	
