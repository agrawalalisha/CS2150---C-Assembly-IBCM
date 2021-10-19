	;; Name: Alisha Agrawal
	;; ID: aa3se
	;; Date: 04-22-2021
	;; binarySearch.s

	global binarySearch

	section .text

binarySearch:
	xor eax, eax		; zero out return register
	xor r10d, r10d		; zero out middle index

start:
	cmp esi, edx		; if esi > edx, goto end
	jg end

	mov r10d, edx		; mov high into r10d
	add r10d, esi		; low + high
	shr r10d, 1		; middle = low+high / 2

	cmp ecx, [edi+4*r10d]	; if target < a[i]
	jl lesser		; goto lesser

	cmp ecx, [edi+4*r10d]	; if target > a[i]
	jg greater		; goto greater

	jmp done

lesser:
	mov edx, r10d		; mov middle into high
	dec edx			; high - 1
	jmp start	

greater:
	mov esi, r10d		; mov middle into low
	inc esi			; low + 1
	jmp start

end:
	mov eax, -1		; not found
	ret

done:
	mov eax, r10d		; return found index
	ret
