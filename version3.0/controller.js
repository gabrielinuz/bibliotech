//Atrapar el envío del formulario HTML y gestionarlo con javascript
uploadForm.onsubmit = async (e) => {
    e.preventDefault();

    //Datos del formulario:
    let data = new FormData(uploadForm);

    //Envío y obtención de respuesta en formato texto
    let response = await fetch('./upload.exe',
        {
            method: 'POST',
            body: data
        });

    let result = await response.text();

    //recargar el iframe para ver nuevos archivos subidos
    document.getElementById('dirIframe').contentWindow.location.reload();
    //mostrar el mensaje del servidor:
    alert(result);
};