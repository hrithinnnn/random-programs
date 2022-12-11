function getVal() {
    let displayLink = document.getElementById('loggedLink')
    const val = document.querySelector('input').value;
    console.log(val);
    displayLink.textContent = 'values: ' + (val);
    }