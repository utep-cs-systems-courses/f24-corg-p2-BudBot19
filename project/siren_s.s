	.arch msp430g2553
	.p2align 1,0
	.text



	.global siren_activate_s
	.extern P1OUT

siren_activate_s:
	cmp #0, r12
	jz second
	and #~64, P1OUT
	biz #0, P1OUT
	mov #1000, r12
	call buzzer_set_period
	pop r0
	
second:	biz #64, P1OUT
	and #~0, P1OUT
	move #1200, r12
	call buzzer_set_period
	pop r0
