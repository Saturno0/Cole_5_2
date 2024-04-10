def generador (longitud) :
    caracteres = string.ascii_letters + string.digits + string.punctuation
    contrasena = ''.join(secrets.choice(caracteres) for i in range(longitud))
    if comprobador(contrasena, string.ascii_letters) and comprobador(contrasena, string.digits) and comprobador(contrasena, string.punctuation):
            return contrasena
    else:
        generador (longitud)
    
def comprobador (contrasena, char):
    a = 0
    for i in range(len(contrasena)):
        if contrasena[i] in char:
            a+=1
    if a == (33*logitud)/100:
        return True
    else :
        generador(len(contrasena))
        

def run():
    contrasena = generador(20)
    
        
run()
