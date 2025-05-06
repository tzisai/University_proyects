
//variables

    var Nombre = document.getElementById('name');
    var Nombre_B = document.getElementById('name_b');

    var Dolar = document.getElementById('dolar');
    var Dolar_B = document.getElementById('dolar_b');

    var IMC = document.getElementById('imc');
    var IMC_B = document.getElementById('imc_b');

    var Tamano = document.getElementById('tam');
    var Tamano_B = document.getElementById('tam_b');

    var Concatenar = document.getElementById('conc');
    var Concatenar_B = document.getElementById('conc_b');

    var Convertir = document.getElementById('conv');
    var Convertir_B = document.getElementById('conv_b');

    var Split = document.getElementById('split');
    var Split_B = document.getElementById('split_b');

    var limpiar = document.getElementById('limpiar');

//Funciones
function miNombre(nombre, apellido, edad){
    return 'Me llamo '+nombre+' '+apellido+' y tengo '+edad+' años\r';
}

Nombre_B.onclick = function(e){
    Nombre.value = miNombre('Martin', 'Nuñez', 19)+ "       " + miNombre('Paola', 'Osorio', 19);
}

var valor = 15.4351953;
var dolarAPesos = function(dolar){
    return dolar*valor;
};

Dolar_B.onclick = function(e){
    Dolar.value = dolarAPesos(40);
}

function bmi(peso, altura){
  return peso/(altura**2);
}

IMC_B.onclick = function(e){
    IMC.value = bmi(80, 1.8);
}

let nombre = "Jose";

Tamano_B.onclick = function(e){
    Tamano.value = nombre.length;
}

Concatenar_B.onclick = function(e){
    Concatenar.value = nombre.concat('','Aguilar');
}

Convertir_B.onclick = function(e){
    Convertir.value = nombre.toUpperCase();
}

let mensaje = "Aprendiendo JavaScript con Jose Aguilar";

Split_B.onclick = function(e){
    Split.value = mensaje.split(' ');
}

limpiar.onclick = function(e){
    Nombre.value = '';
    Dolar.value = '';
    IMC.value = '';
    Tamano.value = '';
    Concatenar.value = '';
    Convertir.value = '';
    Split.value = '';
}
