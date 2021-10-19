	;; Name: Alisha Agrawal
	;; ID: aa3se
	;; Date; 04/14/2021
	;; linearSearch.s

	global linearSearch

	section .text

linearSearch:

	xor	eax, eax		; zero out the return register
	xor	r10d, r10d		; zero out counter i

start:
	cmp	r10d, esi		; if(i>=size)
	jge	notFound	

	cmp	edx, [edi + 4*r10d] 	; if(target==value)
	je	found			; return index

	inc	r10d			; i++
	jmp	start

notFound:
	mov	eax, -1			; return -1
	ret

found:
	mov	eax, r10d		; return index of target
	ret 
