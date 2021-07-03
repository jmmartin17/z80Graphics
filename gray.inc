dither:
	di
	ld a,$80
	out ($10),a
	ld a,1	
	xor (iy+asm_flag3)
	and 1
	ld (iy+asm_flag3),a	
	jr z,+_
	ld de,splasha		
	jr ++_			
_:
	ld de,splashb		
_:
	ld hl,plotsscreen
	push de
	push hl
	ld hl,sprite_buf
	ld de,sprite_buf+1
	ld bc,127
	ld (hl),0
	ldir
	ld a,(direction)
	ld d,0
	ld e,a
	ld ix,player_sprite_l
	add ix,de
	ld a,(player_y)
	ld h,d
	ld l,a
	add hl,hl
	ld de,sprite_buf
	add hl,de
	ld b,8
_:
	ld a,(ix+0)
	ld (hl),a
	inc hl
	ld a,(ix+1)
	ld (hl),a
	inc hl
	inc ix
	inc ix
	djnz -_
	pop hl
	pop de
	ld c,5
copy_loop:
	ld a,$80
	out ($10),a
	ld b,64			;7
	ld a,$25		;7
	sub c			;4
	inc hl			;6
	dec hl			;6
	inc hl			;6
	dec hl			;6
	inc hl			;6
	dec hl			;6
	inc hl			;6
	dec hl			;6
	inc hl			;6
	dec hl			;6
	inc hl
	dec hl
	out ($10),a
_:
	ld a,(de)		;7
	or (hl)			;7
	push bc			;11
	ld bc,12		;10
	add hl,bc		;11
	ex de,hl		;4
	add hl,bc		;11
	ex de,hl		;4
	pop bc			;10
	out ($11),a
	djnz -_			;13/8
	push bc			;11
	ld bc,-767		;10
	add hl,bc		;11
	ex de,hl		;4
	add hl,bc		;11
	ex de,hl		;4
	pop bc			;10
	dec c			;4
	jr nz,copy_loop		;10/1
	ld ix,sprite_buf
	ld c,2
copy_loop_2:
	ld a,$80
	out ($10),a
	ld b,64
	ld a,$27
	sub c
	inc hl
	dec hl
	inc hl
	dec hl
	inc hl
	dec hl
	inc hl
	dec hl
	out ($10),a
_:
	ld a,(de)
	or (hl)
	or (ix+0)
	push bc
	ld bc,12
	add hl,bc
	ex de,hl
	add hl,bc
	ex de,hl
	pop bc
	inc ix
	inc ix
	out ($11),a
	djnz -_
	push bc
	ld bc,-767
	add hl,bc
	ex de,hl
	add hl,bc
	ex de,hl
	ld bc,-127
	add ix,bc
	pop bc
	dec c
	jr nz,copy_loop_2
	ld c,5
copy_loop_3:
	ld a,$80
	out ($10),a
	ld b,64
	ld a,$2C
	sub c
	inc hl
	dec hl
	inc hl
	dec hl
	inc hl
	dec hl
	inc hl
	dec hl
	out ($10),a
_:
	ld a,(de)
	or (hl)
	push bc
	ld bc,12
	add hl,bc
	ex de,hl
	add hl,bc
	ex de,hl
	pop bc
	out ($11),a
	djnz -_
	push bc
	ld bc,-767
	add hl,bc
	ex de,hl
	add hl,bc
	ex de,hl
	pop bc
	dec c
	jr nz,copy_loop_3
	ret