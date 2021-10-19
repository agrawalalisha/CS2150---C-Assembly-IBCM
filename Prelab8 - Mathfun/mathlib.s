	;; Name: Alisha Agrawal
	;; ID: aa3se
	;; Date: 04/12/2021
	;; mathlib.s


	global product
	global power

	section	.text

product:
	xor	rax, rax	; zero out the return register
	xor	r10, r10	; zero out the counter i

start:
	cmp 	r10, rsi	; if(i==n)
	je	done		; goto end
	add	rax, rdi	; add x to result
	inc	r10		; i++
	jmp	start		; loop
	
done:
	ret		

power:
	xor	rax, rax	; zero out the return register
	mov	rax, 1

	cmp	rsi, 0		;if(rsi==0)
	je	end		;goto end

recurse:
	dec	rsi
	call	power		; call recursively
	mov	rsi, rax	; result into rsi
	call	product		; multiply

end:
	ret
	
	
