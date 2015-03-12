__start__:
	doxygen Doxyfile 2> doxy.log
	(cat doxy.log; echo; echo 'Nacisnij klawisz "Q" aby zakonczyc.') | less

clean:
	rm -fr html doxy.log
