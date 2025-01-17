// Simple array for email recipients
let emailList = [];

// Load saved recipients when the page loads
function loadEmailList() {
    emailList = JSON.parse(localStorage.getItem('emailList') || '[]');
}

// Add professor to email list
function addProfToEmailList(profId) {
    const prof = getProfessorById(profId);
    if (!prof) return;

    // Add to array if not already there
    if (!emailList.some(p => p.id === prof.id)) {
        emailList.push(prof);
        // Save to localStorage
        localStorage.setItem('emailList', JSON.stringify(emailList));
        alert(`Added ${prof.name} to email list`); // Feedback for user
        updateEmailDisplay(); // Update the display
    }
}

// Update the email page display
function updateEmailDisplay() {
    const recipientList = document.getElementById('recipient-list');
    if (!recipientList) return;

    // Clear current list
    recipientList.innerHTML = '';

    // Get current list from localStorage
    const currentList = JSON.parse(localStorage.getItem('emailList') || '[]');

    if (currentList.length === 0) {
        recipientList.innerHTML = '<p>No recipients selected</p>';
        return;
    }

    // Create header with count
    const header = document.createElement('div');
    header.className = 'recipients-header';
    header.innerHTML = `<h3>Recipients (${currentList.length})</h3>`;
    recipientList.appendChild(header);

    // Add each professor to the display
    currentList.forEach(prof => {
        const recipientDiv = document.createElement('div');
        recipientDiv.className = 'recipient-entry';
        recipientDiv.innerHTML = `
            <span class="recipient-name">${prof.name}</span>
            <span class="recipient-email">${prof.email}</span>
        `;
        recipientList.appendChild(recipientDiv);
    });
}

// Initialize when page loads
document.addEventListener('DOMContentLoaded', () => {
    loadEmailList();
    updateEmailDisplay();
});

document.addEventListener('DOMContentLoaded', function() {
    const emailForm = document.getElementById('email-form');
    const recipientListDiv = document.getElementById('recipient-list');

    // Retrieve the broadcast list from local storage
    const broadcastList = JSON.parse(localStorage.getItem('broadcastList')) || [];

    // Display the list of recipients
    recipientListDiv.innerHTML = broadcastList.map(name => `<p>${name}</p>`).join('');

    emailForm.addEventListener('submit', function(event) {
        event.preventDefault();

        const senderEmail = document.getElementById('sender-email').value;
        const emailSubject = document.getElementById('email-subject').value;
        const emailMessage = document.getElementById('email-message').value;

        // Create a mailto link
        const mailtoLink = `mailto:?subject=${encodeURIComponent(emailSubject)}&body=${encodeURIComponent(emailMessage)}`;

        // Open the mailto link
        window.location.href = mailtoLink;
    });
}); 