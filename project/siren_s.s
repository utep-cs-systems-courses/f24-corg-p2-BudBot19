	.arch msp430g2553
	.p2align 1,0
	.text



	.global siren_activate
	.extern P1OUT

siren_activate:
	sub #1, r1
	mov r12, 0(r1)
	cmp #0, 0(r1) //if siren_state is zero jmp to the else statement
	jz second
	and #~64, P1OUT //turns off red led
	biz #0, P1OUT  //turns on green led
	mov #1000, r12
	call buzzer_set_period
	jmp done
	
second:	biz #64, P1OUT
	and #~0, P1OUT
	mov #1200, r12
	call buzzer_set_period
	jmp done

done: 	pop r0
	
