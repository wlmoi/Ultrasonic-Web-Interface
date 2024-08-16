// frontend/script.js

async function getDistance() {
    try {
        const response = await fetch('https://your-cloud-function-url/api/distance');
        const distance = await response.json();
        document.getElementById('distance').innerText = distance;
    } catch (error) {
        console.error('Error fetching distance:', error);
        document.getElementById('distance').innerText = 'Error';
    }
}

setInterval(getDistance, 1000);
